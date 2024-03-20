#!/bin/bash

mysqld_safe --datadir='/var/lib/mysql' &
until mysqladmin ping --silent; do
    echo "Waiting for MariaDB server to be available..."
    sleep 1
done

mysql -e "SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$MYSQL_ROOT_PASSWORD');"
mysql -e "DELETE FROM mysql.user WHERE User='';"
mysql -e "DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');"
mysql -e "DROP DATABASE IF EXISTS test;"
mysql -e "DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';"
mysql -e "FLUSH PRIVILEGES;"
mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"
mysql -e "SELECT 1 FROM mysql.user WHERE user = '$MYSQL_USER'" | grep -q 1 || \
mysql -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';"
mysql -e "FLUSH PRIVILEGES;"

mysqladmin -uroot -p"${MYSQL_ROOT_PASSWORD}" shutdown

exec mysqld_safe --datadir='/var/lib/mysql'

