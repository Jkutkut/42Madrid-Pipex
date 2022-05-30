
echo "Enter pid of pipex:"
read pid
while true; do
	lsof -p $pid | grep CHR
	sleep 0.5
	clear
done
