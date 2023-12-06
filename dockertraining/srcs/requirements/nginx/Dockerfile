# NGINX Dockerfile
FROM debian:bullseye-slim

# Install NGINX and generate self-signed TLS certificate
RUN apt-get update && \
    apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/* && \
    mkdir -p /run/nginx && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/nginx.key -out /etc/nginx/nginx.crt \
    -subj "/C=US/ST=State/L=City/O=Organization/CN=localhost"

# Copy NGINX configuration file
COPY nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
