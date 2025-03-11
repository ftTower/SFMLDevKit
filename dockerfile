FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
	g++ \
	cmake \
	libsfml-dev \
	&& rm -rf /var/lib/apt/lists/*
	
	WORKDIR /app
	
	COPY . .
	
	RUN make
	
	CMD ["./SFMLDevKit"]