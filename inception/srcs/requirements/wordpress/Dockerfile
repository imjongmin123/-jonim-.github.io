FROM  debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install wget php7.4-fpm php-mysql mariadb-client unzip && \
    apt-get install -y dumb-init

RUN wget -O wp-cli.phar https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html

RUN wget https://wordpress.org/latest.zip \
    && unzip latest.zip \
    && rm latest.zip \
    && mv wordpress/* ./ \
    && rmdir wordpress

RUN mkdir -p /run/php
RUN chown www-data:www-data /run/php

RUN if [ -f /var/www/html/wp-config.php ]; then rm /var/www/html/wp-config.php; fi

COPY ./conf/wp-config.php /var/www/html/wp-config.php
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY start.sh /usr/local/bin/start.sh

RUN chmod +x /usr/local/bin/start.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--", "/usr/local/bin/start.sh"]
