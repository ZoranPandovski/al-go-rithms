<?php

function caesarCipher($text, $rotate)
{
    $text = strtoupper($text);
    $alphabet = range('A', 'Z');
    $encryptedText = "";
    for ($i = 0; $i < strlen($text); $i++) {
        $letterIndex = array_search($text[$i], $alphabet);
        if ($letterIndex === false) {
            $encryptedText .= " ";
            continue;
        }
        $shiftedIndex = ($letterIndex + $rotate) % count($alphabet);
        $encryptedText .= $alphabet[$shiftedIndex];
    }
    
    return $encryptedText;
}

function caesarCipherTests()
{
    $testFailed = false;
    if (caesarCipher("TEST", 11) != "EPDE") {
        echo "Wrong encrypted text for input `TEST` and rotation 11" . PHP_EOL;
        $testFailed = true;
    }
    
    if (caesarCipher("TO BE OR NOT TO BE", 21) != "OJ WZ JM IJO OJ WZ") {
        echo "Wrong encrypted text for input `TO BE OR NOT TO BE` and rotation 21" . PHP_EOL;
        $testFailed = true;
    }
    
    if (caesarCipher("JHLZHY JPWOLY", 19) != "CAESAR CIPHER") {
        echo "Wrong encrypted text for input `JHLZHY JPWOLY` and rotation 7" . PHP_EOL;
        $testFailed = true;
    }
    
    if (caesarCipher("CAESAR CIPHER", 7) != "JHLZHY JPWOLY") {
        echo "Wrong encrypted text for input `CAESAR CIPHER` and rotation 7" . PHP_EOL;
        $testFailed = true;
    }
    
    if (!$testFailed) {
        echo "All tests finished without errors.";
    }
}

caesarCipherTests();
