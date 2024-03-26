# Efficient-Fuel-Management
You have been selected by a car dealer to efficiently organize the cars and their fuel consumption as part of a research project to increase vehicle efficiency and reduce pollution.

There are several types of cars, namely: internal combustion engine cars (which can be those running on gasoline and those running on diesel), hybrids, and full electric cars. Cars are characterized by their type, as presented above, and the following:

For each type of car, consumption can be calculated as follows:

Gasoline - (0.879 * average_consumption * number_of_kilometers) / 100;
Diesel - (0.789 * average_consumption * number_of_kilometers) / 100;
Hybrid - (average_consumption * number_of_kilometers - 0.124 * number_of_kilometers) / 100;
Electric - 0.

For example, a car that has traveled 100 km on gasoline with an average consumption of 5 L/100 km will consume 0.879 * 5 * 100 / 100 = 4.39 L of gasoline.

Considering that the price of gasoline is 4.5 lei/L, and diesel is 4.8 lei/L, the total price of fuel can be calculated (assuming hybrid cars run on gasoline).

Requirement (a)
Sort the list of cars as follows: if the year of manufacture differs, then display them in descending order of years; otherwise, if the number of kilometers traveled differs, then sort them in ascending order by the number of kilometers. In case of the same number of kilometers, sort them in descending order by average consumption. Then display them in the format:

Car <brand> with license plate <number> has traveled <nr_km>km and consumed <average_consumption> liters.

Requirement (b)
Calculate the total amount paid by the dealership for the number of kilometers traveled by each car and display it with exactly two decimal places.

Requirement (c)
After reading the character 'c', representing the requirement, read cars again until EOF, in the same format as above, and add them to the existing collection. Then display the total number of kilometers traveled by cars, as well as the average consumption per hundred kilometers, with exactly three decimal places, in the format:

<total_distance> km
<average_consumption> L/100km

Requirement (d)
Produce a statistic of the number of cars of each type (gasoline, diesel, electric, hybrid), namely how many cars of that type exist, and display it in the format:

gasoline -> <nr_gasoline_cars>
diesel -> <nr_diesel_cars>
electric -> <nr_electric_cars>
hybrid -> <nr_hybrid_cars>

Requirement (e)
Analyze the database and determine which license plate numbers are NOT correct. A correct license plate number consists of one or two letters followed by two or three digits, followed by exactly three letters. All letters must be uppercase. If a number is incorrect, display:

<license_plate_number>: invalid license plate number

Input:
The first line contains an integer n, representing the number of cars to be read. The next n lines contain information about the cars, in the format:

<brand> <fuel_type> <license_plate> <manufacture_year> <average_consumption> <number_of_km>
The last line contains a character from the range [a-e] representing the requirement to be addressed.

Output:
The values ​​will be displayed at the output according to the specification from the examples below, without displaying any additional text in the console! Display only the requested result with a newline character included after the last line.
