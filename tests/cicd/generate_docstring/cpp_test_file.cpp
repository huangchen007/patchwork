#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <sqlite3.h>


template<typename T>
/**
 * Adds two values of type T and returns the result.
 * 
 * @param a First value of type T to be added.
 * @param b Second value of type T to be added.
 * @return The sum of a and b.
 */
T a_plus_b(T a, T b) {
    return a + b;
}


/**
 * Executes a SQL query on the given SQLite database and returns the results as a vector of string vectors, 
 * where each inner vector represents a row of the query results.
 * 
 * @param db A pointer to the SQLite database connection on which the query will be executed.
 * @param query A string containing the SQL query to be executed.
 * @return A vector of vectors of strings, representing the rows and columns of the query result. 
 *         If the query preparation fails, an empty vector is returned.
 */
std::vector<std::vector<std::string>> sqlite(sqlite3* db, const std::string& query) {
    std::vector<std::vector<std::string>> results;
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return results;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); i++) {
            const unsigned char* text = sqlite3_column_text(stmt, i);
            if (text) {
                row.push_back(std::string(reinterpret_cast<const char*>(text)));
            } else {
                row.push_back("");
            }
        }
        results.push_back(row);
    }

    sqlite3_finalize(stmt);
    return results;
}


template<typename T, typename F>
/**
 * Compares two items using a key mapping function.
 * 
 * This function retrieves mapped values of the two items using the provided key mapping function, then 
 * compares these mapped values.
 * 
 * @tparam F A callable type that maps a T-type item to a comparable value.
 * @tparam T The type of the items to compare.
 * @param key_map A function or functor that maps an item of type T to a comparable value.
 * @param item1 The first item to compare.
 * @param item2 The second item to compare.
 * @return -1 if the mapped value of `item1` is less than the mapped value of `item2`, 
 *          1 if the mapped value of `item1` is greater than the mapped value of `item2`,
 *          0 if both mapped values are equal.
 */

int compare(F key_map, const T& item1, const T& item2) {
    auto val1 = key_map(item1);
    auto val2 = key_map(item2);

    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}


/**
 * Generates a random string of alphabets with a specified length.
 * The string can contain both lowercase and uppercase letters.
 * 
 * @param length The length of the random string to generate.
 * @return A random string composed of alphabetic characters with the specified length.
 */
std::string random_alphabets(int length) {
    static const std::string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    static std::random_device rd;
    static std::mt19937 generator(rd());
    static std::uniform_int_distribution<> distribution(0, chars.size() - 1);

    std::string result;
    result.reserve(length);

    for (int i = 0; i < length; ++i) {
        result += chars[distribution(generator)];
    }

    return result;
}