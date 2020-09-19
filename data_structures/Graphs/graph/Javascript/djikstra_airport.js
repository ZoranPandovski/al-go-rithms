/*
    Story: There are various airports in a country. Each airport has its latitude and longitude.
    Given 2 airports A1 and A2, you need to find out the minimum distance travelled to reach from A1 to A2.

    Constraints:
    1. The airports which can be directly travelled from an airport will be given.
	2. You need to find the minimum distance (not displacement) between A1 and A2.
	3. If there is no way to reach from A1 to A2, then print -1.

    Input:
    Given the following inputs
    1. latitudes = [0, 0, 70];
    2. longitudes = [90, 0, 45];
    3. canTravelDirectly = ['2', '0 2', '0 1'];
    
    Problem: Write a function shortestTrip(latitudes, longitudes, canTravelDirectly, airport1_index, airport2_index).
    It will return the minimum distance(datatype: float) travelled to reach from A1 to A2.

    Explanation of Input:
    Airport 0 : { latitude: 0, longitude: 90 }
    Airport 1 : { latitude: 0, longitude: 0 }
    Airport 2 : { latitude: 70, longitude: 45 }

    From Airport 1, you can directly travel to [ 'Airport 2' ] only
    From Airport 2, you can directly travel to [ 'Airport 0', 'Airport 2' ]
    From Airport 2, you can directly travel to [ 'Airport 0', 'Airport 1' ]


    shortestTrip(latitudes, longitudes, canTravelDirectly, 0, 1) will find the minimm distance 
    travelled between A0 and A1  
*/

// This is a function used to calculate the earth's arc length between two points on the map
function getDistance(coord1, coord2) {
	let radius = 4000;
	let { lat: lat1, lon: lon1 } = coord1;
	let { lat: lat2, lon: lon2 } = coord2;

	let distance = radius * Math.acos(Math.sin(lat1) * Math.sin(lat2) + Math.cos(lat1) * Math.cos(lat2) * Math.cos(lon1 - lon2));
	return distance;
}

function shortestTrip(latitude, longitude, canTravel, origin, destination) {
	// Total number of airports
	let n = latitude.length;

	// Create a map of all airports with their corresponding coordinates
	var map = {};
	for (let i = 0; i < latitude.length; i++) {
		let lat = latitude[i],
			lon = longitude[i];
		map[i.toString()] = { lat, lon };
	}

	// Create an adjancency map having "Airport -> Neighbouring airports"
	var adjancency = {};
	for (let i = 0; i < canTravel.length; i++) {
		adjancency[i.toString()] = canTravel[i].split(' ');
	}

	return djikstra(n, map, adjancency, origin, destination);
}

function djikstra(n, map, adjancency, origin, destination) {
	// Keep a distances array
	let distances = new Array(n).fill(1000000);
	distances[origin] = 0;

	// Keep a parents array
	let parent = new Array(n).fill(null);

	let queue = distances.slice();

	let airportIndex = getMinDistIndex(queue);
	let x = 0;
	while (airportIndex > -1 && x++ < 10) {
		airportIndex = getMinDistIndex(queue);
		if (airportIndex == -1) {
			break;
		}
		// console.log('\nAirport Index: ', airportIndex);
		// console.log('parent: ', parent);
		// console.log('distances: ', distances);
		// console.log('queue: ', queue);
		queue[airportIndex] = null;

		let airportCoord = map[airportIndex.toString()];
		let neighbours = adjancency[airportIndex.toString()];
		// console.log('neighbours: ', neighbours);
		for (let i = 0; i < neighbours.length; i++) {
			let nbr = parseInt(neighbours[i]);
			let neighbourCoord = map[nbr.toString()];
			let distanceToReach = getDistance(airportCoord, neighbourCoord);
			// console.log(`parent: ${airportIndex}, neighbour: ${nbr}, distance: ${distanceToReach}`);

			if (distances[airportIndex] + distanceToReach < distances[nbr]) {
				distances[nbr] = distances[airportIndex] + distanceToReach;
				queue[nbr] = distances[airportIndex] + distanceToReach;
				parent[nbr] = airportIndex;
			}
		}
	}

	// console.log('\n Final parent: ', parent);
	// console.log('distances: ', distances);

	if (distances[destination] === 1000000) {
		return -1.0;
	}
	return parseFloat(distances[destination]);
}

function getMinDistIndex(airports) {
	let min = 1000000;
	let minIndex = -1;

	for (let i = 0; i < airports.length; i++) {
		let airportDistance = airports[i];

		if (airportDistance !== null && airportDistance < min) {
			min = airportDistance;
			minIndex = i;
		}
	}

	return minIndex;
}

// Input Case 0
var lats = [0, 0, 70];
var lons = [90, 0, 45];
var canTravel = ['2', '0 2', '0 1'];
var shortest = shortestTrip(lats, lons, canTravel, 0, 1);
console.log('\n==========\nFinal answer: ', shortest);

// Input Case 1
var lats = [0, 0, 70];
var lons = [90, 0, 45];
var canTravel = ['1 2', '0 2', '0 1'];
var shortest = shortestTrip(lats, lons, canTravel, 0, 1);
console.log('\n==========\nFinal answer: ', shortest);

// Input Case 1
var lats = [0, 20, 55];
var lons = [-20, 85, 42];
var canTravel = ['1', '0', '0'];
var shortest = shortestTrip(lats, lons, canTravel, 0, 2);
console.log('\n==========\nFinal answer: ', shortest);
