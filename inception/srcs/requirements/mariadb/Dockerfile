FROM debian:bullseye

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get -y install mariadb-server && \
	apt-get install -y vim && \
	apt-get install -y dumb-init

COPY ./tools/start.sh /start.sh

RUN chmod +x /start.sh

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

ENTRYPOINT ["/usr/bin/dumb-init", "--", "/start.sh"]