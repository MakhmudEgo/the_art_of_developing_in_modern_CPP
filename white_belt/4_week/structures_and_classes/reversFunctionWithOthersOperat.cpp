//
// Created by Mahmud Jego on 3/24/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

class FunctionPart {
public:
	FunctionPart(char new_oper, double new_value)
	{
		operation = new_oper;
		value = new_value;
	}
	double Apply(double src_value) const {
		if (operation == '+') {
			return src_value + value;
		} else if (operation == '-') {
			return src_value - value;
		} else if (operation == '*') {
			return src_value * value;
		} else {
			return src_value / value;
		}
	}
	void Invert() {
		if (operation == '+') {
			operation = '-';
		} else if (operation == '-') {
			operation = '+';
		} else if (operation == '*') {
			operation = '/';
		} else {
			operation = '*';
		}
	}
private:
	char operation;
	double value;
};

class Function {
public:
	void AddPart(char oper, double value) {
		parts.push_back({oper, value});
	}

	double Apply(double value) const {
		for ( const FunctionPart& part : parts)
		{
			value = part.Apply(value);
		}
		return value;
	}

	void Invert() {
		for (FunctionPart& part : parts)
		{
			part.Invert();
		}
		std::reverse(std::begin(parts), std::end(parts));
	}

private:
	std::vector<FunctionPart> parts;
};


Function MakeWeightFunction(const Params& params,
							const Image& image) {
	Function function;
	function.AddPart('*', params.a);
	function.AddPart('-', image.freshness * params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
							  const Image& image,
							  double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}

