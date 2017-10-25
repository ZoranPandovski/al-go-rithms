<?php
/**
 * @author Jose Chavarría
 * @license MIT
 * @link https://chavarria.cr/post/arrays
 */

class Arrays 
{
	function __construct()
	{
		$arrayName = array();
		$this->Insert();
	}

	function Insert(){
		echo("Insert...");
		for ($i=0; $i <5; $i++) { 
			echo '</br>'.'index: '.$i.' value: '.$this->arrayName[]=$i;
		}
	}

	function Traverse(){
		echo("</br></br>Traverse...");
		for ($i=0; $i < count($this->arrayName); $i++) { 
			echo '</br>'.'index: '.$i.' value: '.$this->arrayName[$i];
		}
	}

	function Update($past, $var){
		echo ("</br></br>Update: ".$past." to ".$var);
		for ($i=0; $i < count($this->arrayName); $i++) { 
			if($this->arrayName[$i]==$past){
				echo '</br>'.'index: '.$i.' value: '.$this->arrayName[$i] =$var;
			}
		}
	}
	function Search($var){
		echo ("</br></br>Search :".$var);
		for ($i=0; $i < count($this->arrayName); $i++) { 
			if ($this->arrayName[$i]==$var) {
				echo '</br>'.'index: '.$i.' value: '.$this->arrayName[$i];
			} 
		}
	}
	function Deletion($var){
		echo ("</br></br>Deletion: ".$var."</br>");
		$newArray = array(); $aux=0;
		for ($i=0; $i < count($this->arrayName) ;$i++) { 
			if($this->arrayName[$i]!=$var){
				$this->newArray[$aux]=$this->arrayName[$i];
				$aux++;
			}
		}
		$this->arrayName = $this->newArray;
	}
}

$a = new Arrays();
$a->Traverse();
$a->Search(2);
$a->Update(2,100);
$a->Deletion(3);
$a->Traverse();

?>