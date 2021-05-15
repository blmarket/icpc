import java.math.BigInteger

object C3 {
    fun process() {
        val (N, Q) = readLine()!!.split(" ").map { it.toInt() }.run {
            Pair(this[0], this[1])
        }
        IntRange(0, N - 1).forEach {
            val tmp = readLine()!!.split(" ")
            var ans = tmp[0]
            var score = tmp[1].toInt()
            if (score < Q - score) {
                ans = String(ans.map {
                    if (it == 'T') {
                        'F'
                    } else {
                        'T'
                    }
                }.toCharArray())
                score = Q - score
            }
        }

        if (N < 3) {
            println("HELP")
            return
        }

        // state: D[Q][N1,N2,N3]
        IntRange(0, Q - 1).forEach {
            val cur = it % 2;
            val nex = 1 - cur
        }
    }

    @JvmStatic
    fun main(args: Array<String>) {
        val T = readLine()!!.toInt()
        IntRange(1, T).forEach {
            print("Case #" + it + ": ")
            process()
        }
    }
}