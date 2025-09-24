# Start from the latest Ubuntu base image
FROM ubuntu:latest

# Set environment variables to prevent locale-related warnings
ENV DEBIAN_FRONTEND=noninteractive
ENV LANG=C.UTF-8

# Update the package lists and install the build-essential package
# 'build-essential' includes gcc, g++, and make.
# We also install 'vim' as requested by the user.
# The '--no-install-recommends' flag helps keep the image size smaller.
RUN apt-get update && \
    apt-get install -y --no-install-recommends build-essential vim locales gdb && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set up the locale to avoid warnings
RUN locale-gen en_US.UTF-8

# Set the working directory inside the container
# All subsequent commands will be executed in this directory.
WORKDIR /app

# Set the default command to run when the container starts.
# This will open a bash shell, allowing for interactive use.
# CMD ["/bin/bash"] is equivalent to CMD ["bash", "-i"]
CMD ["/bin/bash"]
