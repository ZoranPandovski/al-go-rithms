package algorithms;

import java.math.BigDecimal;
import java.math.RoundingMode;

import data.management.Set;
import elements.Attribute;
import elements.Value;
import exception.ImpossibleException;

public class ID3 extends DecisionTreeLearning{

	public ID3(Set s, String goal) throws ImpossibleException{
		super(s, goal);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void execute() {
		// TODO Auto-generated method stub
		//If all instances in C are positive | negative -> halt algo and create node
		if(set.sameValuesInstance(obj)){
			Value value = set.getOnlyValue(obj);
			// create unique node : TODO
			return; 
		}else{
			double S = entropyObjective();
			System.out.println("Entropy of S = " + S);
			// need to choose which is the best attribute to be the root node
			double gain = 0.0;
			for(Attribute a : attributes){
				gain = entropy(a,obj);
				gain = round(S - gain);
				System.out.println("gain of" + a.getName() + " = " + gain);
			}
		}
	}

	@Override
	protected double gain(Attribute S, Attribute attribute) {
		// TODO Auto-generated method stub
		return round(entropy(S, obj) - entropy(attribute, obj));
	}

	@Override
	protected double entropy(Attribute a, Attribute S) {
		// TODO Auto-generated method stub
		return round(a.entropy(S));
	}
	
	protected double entropyObjective(){
		double res = 0.0;
		double stat = 0.0;
		for(Value v : obj.getAttributes()){
			stat = (v.getOccurences() / set.getSamples());
			res -= stat * log2(stat);
		}
		return round(res);
	}
	
	private double log2(double val){
		if(val == 0){
			return 0.0;
		}else{
			return (Math.log(val) / Math.log(2));
		}
	}
	
	private double round(double toRound){
	    BigDecimal bd = new BigDecimal(toRound);
	    bd = bd.setScale(3, RoundingMode.HALF_UP);
	    return bd.doubleValue();
	}

}
