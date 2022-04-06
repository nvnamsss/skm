#/bin/bash
image_name=skm
echo "BUILDING APPLICATION"
make build
echo "REMOVING OLD IMAGE"
docker image rm -f $image_name
echo "BUILDING NEW IMAGE"
docker build . -t $image_name