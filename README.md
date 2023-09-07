This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.  <br/>

• Global variables are forbidden!  <br/>
• Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]  <br/>
◦ number_of_philosophers: The number of philosophers and also the number
of forks.  <br/>
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.  <br/>
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.  <br/>
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.  <br/>
◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies. <br/>
• Each philosopher has a number ranging from 1 to number_of_philosophers. <br/>
• Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1. <br/>
• A displayed state message should not be mixed up with another message. <br/>
• A message announcing a philosopher died should be displayed no more than 10 ms
after the actual death of the philosopher. <br/>
• Again, philosophers should avoid dying! <br/>
• Each philosopher should be a thread. <br/>
• There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table. <br/>
• To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them. <br/>
