/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {

    if (obj == null || typeof classFunction !== "function") {
        return false;
    }

    let current = Object(obj);

    while (current != null) {

        if (current.constructor === classFunction) {
            return true;
        }

        current = Object.getPrototypeOf(current);
    }

    return false;
};