<?php
function encrypt($str, $offset) {
    $encrypted_text = "";
    $offset = $offset % 26;
    if($offset < 0) {
        $offset += 26;
    }
    $i = 0;
    while($i < strlen($str)) {
        $c = strtoupper($str{$i}); 
        if(($c >= "A") && ($c <= 'Z')) {
            if((ord($c) + $offset) > ord("Z")) {
                $encrypted_text .= chr(ord($c) + $offset - 26);
        } else {
            $encrypted_text .= chr(ord($c) + $offset);
        }
      } else {
          $encrypted_text .= " ";
      }
      $i++;
    }
    return $encrypted_text;
}
function decrypt($str, $offset) {
    $decrypted_text = "";
    $offset = $offset % 26;
    if($offset < 0) {
        $offset += 26;
    }
    $i = 0;
    while($i < strlen($str)) {
        $c = strtoupper($str{$i}); 
        if(($c >= "A") && ($c <= 'Z')) {
            if((ord($c) - $offset) < ord("A")) {
                $decrypted_text .= chr(ord($c) - $offset + 26);
        } else {
            $decrypted_text .= chr(ord($c) - $offset);
        }
      } else {
          $decrypted_text .= " ";
      }
      $i++;
    }
    return $decrypted_text;
}

//sample text
$text = "Hello World";
$offset = 5;

$enc = encrypt($text, $offset);
echo $enc;
echo "<br />";
echo decrypt($enc, $offset);
?>
