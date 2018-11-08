
* Arguments sont doubles pour je ne sais quelle raison

"T8wYxOys" "bzpdY2T"      "T8wYxOys" "bzpdY2T" = 5th push, check function pointer == 0
	-mismatch: T8wYxOys$
	+match: T8wYxOys$
	mismatch: bzpdY2T$

"x" "yTjXADS" "2as" "UylfInBLw" "pNSXAxqvd4" "zj6OuCI3"     "x" "yTjXADS" "2as" "UylfInBLw" "pNSXAxqvd4" "zj6OuCI3" = 4st push, inverted left & right
	-mismatch: x$ = premier argument
	+match: x$
	mismatch: zj6OuCI3$ = dernier argument

"BWLtpKwSJ7" "OzEylMQeD" "4S" "n6B5zQJ" "t" "vNdsw21jGb" "rGq9StM5" "VfEO" "2PGrqpOR4"     "BWLtpKwSJ7" "OzEylMQeD" "4S" "n6B5zQJ" "t" "vNdsw21jGb" "rGq9StM5" "VfEO" = infix
	-mismatch: BWLtpKwSJ7$ = premier argument
	+match: BWLtpKwSJ7$
	mismatch: 2PGrqpOR4$ = dernier argument


"OLVirzW" "ISDNc" "LxG" "TDBpgFNRc2Ji" "9PbMRCzjBr0" "QaYb"     "OLVirzW" "ISDNc" "LxG" "TDBpgFNRc2Ji" "9PbMRCzjBr0" "QaYb" = infix
	-mismatch: OLVirzW$ = premier argument
	+match: OLVirzW$
	mismatch: QaYb$ = dernier argument

"Gyeu2" "UTxPlpzJ" "yG"     "Gyeu2" "UTxPlpzJ" "yG" = 1st push, not infix (return first matching element)
	-mismatch: Gyeu2$ = premier argument
	+match: Gyeu2$
	mismatch: yG$ = dernier argument


• 	Écrire la fonction btree_search_item qui retourne le premier élèment correspondant
	à la donnée de référence passée en paramètre. L’arbre devra être parcouru de
	manière infix. Si l’élément n’est pas trouvé, la fonction devra retourner NULL.

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));

void	*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *))
{
	void	*tmp;

	if (root == 0 || cmpf == 0)
		return (0);
	tmp = btree_search_item(root->left, data_ref, cmpf);
	if (tmp != 0)
		return (tmp);
	if (cmpf(root->item, data_ref) == 0)
		return (root);
	return (btree_search_item(root->right, data_ref, cmpf));
}
