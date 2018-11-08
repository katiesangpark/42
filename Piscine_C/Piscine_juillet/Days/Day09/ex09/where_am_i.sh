if [ "$(ifconfig | grep -Eo '([0-9]*\.){3}[0-9]*' | wc -l | bc)" -eq 0 ]; then
		echo "I am lost!"
	else
		ifconfig | grep -Eo '([0-9]*\.){3}[0-9]*'
	fi