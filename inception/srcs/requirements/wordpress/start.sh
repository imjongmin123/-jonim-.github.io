#!/bin/bash

until mysqladmin -h mariadb -u root -p"$MYSQL_ROOT_PASSWORD" ping --silent; do
    echo "Waiting for MariaDB server to become available..."
    sleep 1
done


wp core install --url="${DOMAIN_NAME}" --title="JONIM'S INCEPTION" --admin_user="${WORDPRESS_ADMIN_USER}" \
--admin_password="${WORDPRESS_ADMIN_PASSWORD}" --admin_email="${WORDPRESS_ADMIN_EMAIL}" \
--path=/var/www/html --allow-root
echo "WordPress installed."


if wp user get ${WORDPRESS_AUTHOR_USER} --path=/var/www/html --allow-root >/dev/null 2>&1; then
  echo "사용자 '${WORDPRESS_AUTHOR_USER}'은(는) 이미 존재합니다."
else
    wp user create "${WORDPRESS_AUTHOR_USER}" "${WORDPRESS_AUTHOR_EMAIL}" --role=author --path=/var/www/html --allow-root
    echo "WordPress setup completed."
fi


exec php-fpm7.4 -F
