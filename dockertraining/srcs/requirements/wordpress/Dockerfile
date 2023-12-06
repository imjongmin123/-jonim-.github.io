# WordPress Dockerfile
FROM debian:bullseye-slim

# Install necessary packages for WordPress and php-fpm
RUN apt-get update && \
    apt-get install -y php-fpm php-mysql && \
    rm -rf /var/lib/apt/lists/*

# Copy WordPress files
COPY wordpress /var/www/html

CMD ["php-fpm", "-F"]
