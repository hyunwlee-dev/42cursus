/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:32:28 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/10/09 16:31:41 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmd_id(char *cmd, t_cmd *cmd_id)
{
	char	**cmd_partitions;

	cmd_partitions = ft_split(cmd, ' ');
	cmd_id->cmd[0] = ft_strjoin("/usr/local/bin/", cmd_partitions[0]);
	cmd_id->cmd[1] = ft_strjoin("/usr/bin/", cmd_partitions[0]);
	cmd_id->cmd[2] = ft_strjoin("/bin/", cmd_partitions[0]);
	cmd_id->cmd[3] = ft_strjoin("/usr/sbin/", cmd_partitions[0]);
	cmd_id->cmd[4] = ft_strjoin("/sbin/", cmd_partitions[0]);
	cmd_id->argv = cmd_partitions;
}

int		run_execve(char *cmd, t_cmd *cmd_id)
{
	int	i;

	i = 0;
	init_cmd_id(cmd, cmd_id);
	while (i < 5)
		execve(cmd_id->cmd[i++], cmd_id->argv, cmd_id->envp);
	perror(cmd_id->argv[0]);
	return (1);
}

int		main(int argc, char *argv[])
{
	t_total	total;

	if (check_validation_args(argc, argv, &total))
		return (0);
    // 기능: 서로 독립된 프로세스들이 데이터를 주고 받을 수 있도록 해주는 함수
    // 하나의 파이프 및 파이프에 대한 두 개의 파일 디스크립터가 생성
    // 하나의 파이프를 프로세스들이 공유
	pipe(total.pipefd);
    
	total.pid = fork(); // why don't use exec() system call?.. cow? (copy-on-wirte)
	if (total.pid == CHILD) // "사람의 세계로 보면 잔인하다. 자식이 사치를 한다고 죽이고, 자식이 이제 필요없어서 죽이고, 부모가 죽기직전 죽인다."
	{
		if (redirect_in(total.args.input_file) || \
			connect_pipe(total.pipefd, STDOUT_FILENO) || \
			run_execve(total.args.cmd1_text, &total.cmd1))
			exit(1);
	}
	else if (total.pid > 0)
	{
		waitpid(total.pid, &total.status, 0);
		if (WIFEXITED(total.status) == 0)
			exit(1);
		if (redirect_out(total.args.output_file) || \
			connect_pipe(total.pipefd, STDIN_FILENO) || \
			run_execve(total.args.cmd2_text, &total.cmd2))
			exit(1);
	}
	return (0);
}

// fork()
// fork()를 만나면 자식 프로세스가 생성이 된다.
// 여기서 재귀처럼 자식 프로세스가 실행되고 부모 프로세스가 실행되는 것이 아니다.
// 부모 프로세스는 아무일 없다는 듯이 바로 다음 코드를 수행한다.
// 자식 프로세스는 main() 시작부터 시작하는 것이 아니라 fork()이후 시점부터 시작한다.
// fork()를 통해 context를 그대로 복사하게 될 텐데, PC도 그대로 복사되었기 때문에 fork()이후 시점부터 시작한다.
// 복제하면 문제점: 자기가 원본이라 우긴다. 혼란스러워 진다. => 자식과 부모를 구분해준다. (fork()의 return value가 다름)


// wait()
// 부모가 wait() 시스템 콜을 호출하면
// 커널은 child가 종료될 때까지 부모를 sleep시킨다. (block 상태)
// Child process가 종료되면 커널은 부모를 깨운다. (ready 상태)

/**
 *  
 *  int main()
 *  {
 *      int pid;
 * 
 *      pid = fork();
 *      if (pid == 0)
 *          printf("\n Hello, I am child\n");
 *      else if (pid > 0)
 *          printf("\n Hello, I am parent\n");
 *  }
 */
//[여기서 42 pipex는 왜 exec()를 사용하지 않았을 까요?] 

// 이건 하나의 프로그램이다. 하나의 실행파일을 실행시켜서 똑같은 주소공간을 가진 2개의 프로세스이다.
// 제어 흐름에서는 다른 브랜치로 나아갈 수 있지만 같은 코드를 가지는 프로그램을 가지게 된다.
// 실제로는 이렇지는 않다.
// subj에서 사용할 수 있는 함수가 제한적이여서 이렇게 코딩을 할수 없었다고 본다.