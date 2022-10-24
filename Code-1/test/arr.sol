pragma solidity^0.8.0;

contract test{
    bytes5 public rand = 0x1122334455;
    string tnnd = "nmsl";
    function test1() public returns (bytes1){
        return bytes1(rand);
    }
    function test2() public returns (bytes5){
        return bytes5(rand);
    }
    function test3() public returns (bytes10){
        return bytes10(rand);
    }
    function test4() public returns (string){
        return string(tnnd);
    }
    
}