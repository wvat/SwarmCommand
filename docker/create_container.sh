#!/bin/bash
IMAGE_NAME=fvatnsdal/swarm_ws:latest
SWARM_WS_DIR=${1}

SWARM_VOLUME="--volume=${SWARM_WS_DIR}:/opt/swarm_ws:rw"
CONTAINER_NAME="swarm-${USER}"

docker run -it \
    --name=$CONTAINERNAME \
    --net=host \
    --privileged \
    ${SWARM_VOLUME} \
    --ipc=host \
    ${IMAGE_NAME} \
    bash
