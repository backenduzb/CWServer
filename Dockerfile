FROM gcc:latest

WORKDIR /webserver

COPY . .

RUN make build

CMD ["./webserver"]