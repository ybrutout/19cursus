#!/bin/bash

RED='\033[0;31m'
NC='\033[0m'

# The test 1 with 10 chars.
startTime=$(date +%s);
./client 44268 "Lorem 1237"
endTime=$(date +%s);

totalTime=$(($endTime-$startTime));
echo -e "Execution time for 10 chars ${RED}$totalTime ${NC}sec";

# The test 2 with 100 chars.
startTime=$(date +%s);
./client 44268 "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean m"
endTime=$(date +%s);

totalTime=$(($endTime-$startTime));
echo -e "Execution time for 100 chars ${RED}$totalTime ${NC}sec";

# The test 3 with 1000 chars.
startTime=$(date +%s);
./client 44268 "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. N"
endTime=$(date +%s);

totalTime=$(($endTime-$startTime));
echo -e "Execution time for 1000 chars ${RED}$totalTime ${NC}sec";

exit 0;
