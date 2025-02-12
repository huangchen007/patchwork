package org.example

import java.sql.Connection
import java.sql.ResultSet
import kotlin.random.Random


/**
 * Computes the sum of two numbers and returns the result as a double precision floating-point number.
 * This function accepts any data type that extends the Number class.
 * 
 * @param a The first number to be added.
 * @param b The second number to be added.
 * @return The sum of the two numbers as a Double.
 */
fun <T : Number> aPlusB(a: T, b: T): Double = a.toDouble() + b.toDouble()


/**
 * Executes a SQL query on the provided database connection and returns the result as a list of rows.
 * Each row is represented as a list of objects, with each object corresponding to a column value in the result set.
 * 
 * @param db The database connection to execute the query on.
 * @param query The SQL query to be executed.
 * @return A list of lists, where each inner list represents a row of the result set, and each element of the inner list is a column value.
 */
fun sqlite(db: Connection, query: String): List<List<Any?>> {
    db.createStatement().use { statement ->
        statement.executeQuery(query).use { resultSet ->
            val results = mutableListOf<List<Any?>>()
            val columnCount = resultSet.metaData.columnCount

            while (resultSet.next()) {
                val row = mutableListOf<Any?>()
                for (i in 1..columnCount) {
                    row.add(resultSet.getObject(i))
                }
                results.add(row)
            }
            return results
        }
    }
}


/**
 * Compares two items of type T based on a key derived from each item. The key is obtained by 
 * applying a specified key mapping function to each of the items, and the resulting keys are 
 * compared to determine the order of the items.
 * 
 * @param keyMap A function that maps an item of type T to a key of type R, where R is 
 * Comparable. This function is used to extract a comparable key from each item.
 * @param item1 The first item of type T to be compared.
 * @param item2 The second item of type T to be compared.
 * @return An integer representing the order of the items based on their keys: 
 *         - `-1` if the key of `item1` is less than the key of `item2`.
 *         - `1` if the key of `item1` is greater than the key of `item2`.
 *         - `0` if the keys of both `item1` and `item2` are equal.
 */
fun <T, R : Comparable<R>> compare(keyMap: (T) -> R, item1: T, item2: T): Int {
    return when {
        keyMap(item1) < keyMap(item2) -> -1
        keyMap(item1) > keyMap(item2) -> 1
        else -> 0
    }
}


/**
 * Generates a random string consisting of alphabetic characters of a specified length.
 * The generated string includes both lowercase and uppercase letters.
 * 
 * @param length The desired length of the random string to be generated.
 * @return A randomly generated string composed of alphabetic characters.
 */
fun randomAlphabets(length: Int): String {
    val charPool = ('a'..'z') + ('A'..'Z')
    return (1..length)
        .map { charPool[Random.nextInt(0, charPool.size)] }
        .joinToString("")
}