const cling = require('../build/Release/cling.node');

interface Cling {
    evaluate(s: string): any
}


export default cling as Cling;

