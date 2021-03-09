#!/bin/bash

chmod 775 /run.sh
chown -R www-data:www-data /var/www/
chmod -R 755 /var/www/

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout hyunwlee.key -out hyunwlee.crt
mv hyunwlee.crt etc/ssl/certs/
mv hyunwlee.key etc/ssl/private/
chmod 600 etc/ssl/certs/hyunwlee.crt etc/ssl/private/hyunwlee.key

cp -rp ./default /etc/nginx/sites-available/

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./wp-config.php /var/www/html/wordpress

service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" \
	| mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'hyunwlee'@'localhost' IDENTIFIED BY '1234';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'hyunwlee'@'localhost' WITH GRANT OPTION;" \
	| mysql -u root --skip-password
	
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
rm phpMyAdmin-5.0.2-all-languages.tar.gz
cp -rp ./config.inc.php /var/www/html/phpmyadmin/

service nginx start
service php7.3-fpm start
service mysql restart

bash
