// https://codeforces.com/problemset/problem/2199/B

fun main() {
    val n = readLine()!!.toInt()
    for (i in 0 until n){
        val (a, b, c, d) = readLine()!!.split(" ").map { it.toInt() }
        
        var ans = 0;
        if(maxOf(a,b) >= minOf(c,d)){
            ans = c-a+d-b;
        }
        else{
            ans = maxOf(c,d) - minOf(a,b);
        }
        
        println(ans)
    }
}