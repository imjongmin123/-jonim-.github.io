# MariaDB Dockerfile
FROM debian:bullseye-slim

# Install MariaDB
RUN apt-get update && \
    apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

# Copy MariaDB configuration file
COPY my.cnf /etc/mysql/my.cnf

EXPOSE 3306

CMD ["mysqld"]
