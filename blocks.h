//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"Vol: ", "pamixer --get-volume-human",	10,		10},
	{"Cpu%: ", "top -bn 2 -d 0.01 | grep '^%Cpu' | tail -n1 | gawk '{print $2+$4+$6}'",	5,		0},
	{"Mem: ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	5,		0},
    {"Bat%: ", "if test -f /sys/class/power_supply/BAT1/capacity; then cat /sys/class/power_supply/BAT1/capacity /sys/class/power_supply/BAT1/status | awk -v d='; ' '{s=(NR==1?s:s d)$0}END{print s}'; else echo 'N/A'; fi", 5, 0},
	{"", "date '+%d-%m-%Y  %R'",					60,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

