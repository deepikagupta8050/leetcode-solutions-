/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function* (arr) {

    for (let item of arr) {

        if (Array.isArray(item)) {
            yield* inorderTraversal(item);
        } else {
            yield item;
        }
    }

};