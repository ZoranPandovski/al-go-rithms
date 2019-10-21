// Try it out at https://groovyconsole.appspot.com/ or with the groovy compiler

// We skip door number 0, so we take an extra in the array
Boolean[] doors = new Boolean[101]

// Let the 100 persons walk
(1..100).each{ Integer i ->
    // Let step through the doors from i, in steps of i
    i.step(100, i) { int j ->
        doors[j] = !doors[j]
    }
}

// Print the result
(1..100).each {
    if( doors[it]) {
        println "Door ${it} is open."
    }
}