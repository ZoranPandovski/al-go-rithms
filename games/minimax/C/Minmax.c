
/* MinMax algorithm with and without Alpha-Beta pruning */

//This is the alpha-Beta pruning version

int minmax_ab( struct configuration conf, int mode, int niv, int alpha, int beta )
{
 	int n, i, score, score2;
 	struct configuration T[100];

   	if ( feuille(conf, &score) )
		return score;

   	if ( niv == 0 )
		return estim( conf );

   	if ( mode == MAX ) {

	   generer_succ( conf, MAX, T, &n );

	   score = alpha;
	   for ( i=0; i<n; i++ ) {
   	    	score2 = minmax_ab( T[i], MIN, niv-1, score, beta );
		if (score2 > score) score = score2;
		if (score > beta) {
			// Coupe Beta
   	      		return beta;
	    	}
	   }
	}
	else  { // mode == MIN

	   generer_succ( conf, MIN, T, &n );

	   score = beta;
	   for ( i=0; i<n; i++ ) {
   	    	score2 = minmax_ab( T[i], MAX, niv-1, alpha, score );
		if (score2 < score) score = score2;
		if (score < alpha) {
			// Coupe Alpha
   	      		return alpha;
	    	}
	   }
	}

        if ( score == +INFINI ) score = +10000;
        if ( score == -INFINI ) score = -10000;

	return score;

}  // minmax_ab


/// This is the version without pruning

int minmax( struct configuration conf, int mode, int niv)
{
 	int n, i, score, score2;
 	struct configuration T[100];

   	if ( feuille(conf, &score) )
		return score;

   	if ( niv == 0 )
		return estim( conf );
    if ( mode == MAX ) {
            score = -INFINI;
   	}else{
            score = +INFINI;
    }
    if ( mode == MAX ) {
	   generer_succ( conf, MAX, T, &n );
	   for ( i=0; i<n; i++ ) {
        score2 = minmax( T[i], MIN, niv-1);
		if (score2 > score) score = score2;
	   }
	}
	else  { // mode == MIN
	   generer_succ( conf, MIN, T, &n );
	   for ( i=0; i<n; i++ ) {
   	    	score2 = minmax( T[i], MAX, niv-1);
		if (score2 < score) score = score2;
	   }
	}

    if ( score == +INFINI ) score = +10000;
    if ( score == -INFINI ) score = -10000;
	return score;
} /// without alpha beta
