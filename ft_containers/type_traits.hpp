#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
	/*We create a class wich always have a member value who is false.*/
	template <class T>
	struct is_integral
	{
		static const bool	value = false;
	};

	/*In all this cases the value will be true and so it's just for these case  is an integral.*/
	template <>
	struct is_integral <bool>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <char>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <char16_t>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <char32_t>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <wchar_t>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <signed char>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <short int>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <int>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <long int>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <long long int>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <unsigned char>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <unsigned short int>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <unsigned long int>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <unsigned int>
	{
		static const bool	value = true;
	};

	template <>
	struct is_integral <unsigned long long int>
	{
		static const bool	value = true;
	};


	/*Théorie : Enable_if va être utilisé losr des surcharges de fonctions. Elle est utile pour déterminer quel est la bonne surcharges qui doit
	être utilisé dans des cas plus ambigus. Exemple : une surcharge d'int et une surcharge d'itérateur.
	Cette fonction va chercher toute sa puissance dans la règle SFINAE = "Substitution Failure Is Not An Error". Cette règle dit que
	remplacement (la substituion) d'un type de variable échoue, le code ne doit pas renvoyer une erreur mais passer à la prochaine
	surcharge possible.

	Pratique : la structure va prendre un booléen et un type. Si le bool équivaut à true, la classe aura en elle un attribut de type égal
	au type reçu en paramètre. À l'inverse ce type restera null si le booléen est vide. Dans notre utilisation à nous, le bool viendra
	la structure is_integral qui définis si un type est integral ou non (sachant qu'un itérateur n'est pas un intégral).
	Donc on fait en sorte que si le type originel n'est pas un integral, enable_if recevra un bool true.
	*/
	template <bool, class T = void>
	struct enable_if
	{};

	template <class T>
	struct enable_if<true, T>
	{ typedef T type; };
};

#endif
