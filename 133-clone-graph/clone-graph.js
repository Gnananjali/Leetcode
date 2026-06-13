/**
 * // Definition for a _Node.
 * function _Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {_Node} node
 * @return {_Node}
 */
 var dfs = function(node, map){
    if(map.has(node)){
        return map.get(node);
    }
    const clone = new Node(node.val);
    map.set(node, clone);

    for(const i of node.neighbors){
        clone.neighbors.push(dfs(i, map));
    }
    return clone;
 }
var cloneGraph = function(node) {
    if(!node) return null;

    const map = new Map();

    return dfs(node, map);
};