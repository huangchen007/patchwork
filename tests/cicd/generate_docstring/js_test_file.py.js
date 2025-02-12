
/**
 * Calculates the sum of two numbers.
 * @param {number}  a - The first number to be added.
 * @param {number}  b - The second number to be added.
 * @returns {number} The sum of the two numbers.
 */
function a_plus_b(a, b) {
    return a + b;
}

/**
 * Compares two objects based on a specified key and returns a numerical indication of their relative sorting order.
 * @param {string} keymap - The key name within the objects 'a' and 'b' whose values are compared.
 * @param {Object} a - The first object to compare.
 * @param {Object} b - The second object to compare.
 * @returns {number} Returns -1 if the value of key in 'a' is less than in 'b'; 
 * 1 if the value in 'a' is greater; and 0 if they are equal.
 */
const compare = function (keymap, a, b) {
    if (a[keymap] < b[keymap]) {
        return -1;
    } else if (a[keymap] > b[keymap]) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Executes a query on a SQLite database and calls a callback function for each row of the result.
 * @param {Object} db - The SQLite database object.
 * @param {string} query - The SQL query to be executed.
 * @param {Function} callback - The function to be called for each row of the result. It receives the row as an argument.
 */
const sqlite = (db, query, callback) => {
    db.serialize(function () {
        db.each(query, callback);
    });
}