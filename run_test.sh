sudo docker kill firm
sudo docker rm firm
sudo docker build . -t firmware
sudo docker run -d --name firm firmware
sudo docker exec firm /bin/sh -c "cd ..;cd inf3995-firmware;make unit FILES=test/project/test_SensorCommands.c;make unit FILES=test/project/test_InformationHandler.c;make unit FILES=test/project/test_CommandHandler.c"
