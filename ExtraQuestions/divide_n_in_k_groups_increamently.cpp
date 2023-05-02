/**
 * 
 *  we have to divide n in k groups so that the final array is non-decreasing
*	[ a1 , a2 , a3 , a4 , a5 , .......... , ak]
* 
* 	e.g:
* 	n = 8 , k = 4
* 
* 	total posibilities
* 
* 	[1,1,1,5]
* 	[1,1,2,4]
* 	[1,1,3,3]
* 	[1,2,2,3]
* 	[2,2,2,2]
* 
* 
* 
* 
*  	Intution : 
* 
* 	dp[n][k] = dp[n-1][k-1]+dp[n-k][k];
* 
* 	dp[n-1][k-1] ===> first element is 1.
*  	dp[n-k][k]   ===> first element is greater than 1.(increamenting all the n positions by 1) 	
* 	
* */

