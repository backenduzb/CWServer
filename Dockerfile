FROM gcc:latest

WORKDIR /webserver

COPY . .

RUN make start