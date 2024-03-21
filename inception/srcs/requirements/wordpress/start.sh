#!/bin/bash

wp core install --url="${DOMAIN_NAME}" --title="JONIM'S INCEPTION" --admin_user="${WORDPRESS_ADMIN_USER}" \
--admin_password="${WORDPRESS_ADMIN_PASSWORD}" --admin_email="${WORDPRESS_ADMIN_EMAIL}" \
--path=/var/www/html --allow-root
echo "WordPress installed."


if wp user get ${WORDPRESS_AUTHOR_USER} --path=/var/www/html --allow-root >/dev/null 2>&1; then
  echo "사용자 '${WORDPRESS_AUTHOR_USER}'은(는) 이미 존재합니다."
else
    wp user create "${WORDPRESS_AUTHOR_USER}" --user_pass="${WORDPRESS_AUTHOR_PASSWORD}" --role=author --path=/var/www/html --allow-root
    echo "WordPress setup completed."
fi
# "${WORDPRESS_AUTHOR_EMAIL}"
exec php-fpm7.4 -F
