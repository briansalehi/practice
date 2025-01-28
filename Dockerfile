from ubuntu:24.04
run apt update && apt install bash
entrypoint ["echo"]
