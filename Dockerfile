FROM debian:bookworm

RUN apt-get update && \
    apt-get install -y apache2 gcc make findutils && \
    a2enmod cgi

COPY cgi.conf /etc/apache2/conf-available/cgi.conf
RUN a2enconf cgi

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 80
CMD ["/entrypoint.sh"]
