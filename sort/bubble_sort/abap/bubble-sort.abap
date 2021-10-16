DATA : ITAB_data       TYPE TABLE OF int4, "Internal Table to accept multiple data
       ITAB            TYPE TABLE OF string,
       wa_current_data type int4, " Work Area for this Internal Table
       wa_bubble_data  TYPE int4,
       lv_lines        TYPE int1,
       lv_data1        TYPE int2,
       lv_data2        TYPE int2,
       lv_current_line TYPE int1.

SELECTION-SCREEN BEGIN OF SCREEN 0100 . "Where we create a Screen 0100
SELECT-OPTIONS: s_data FOR wa_current_data. "Seclect-Option for multiple Input
SELECTION-SCREEN END OF SCREEN 0100.
DATA :   wa_sdata LIKE LINE OF s_data.

START-OF-SELECTION. " Where we show output
  CALL SELECTION-SCREEN '0100' STARTING AT 10 10. "Where we call the Screen 0100 we created earlier.
  LOOP AT s_data INTO wa_sdata.
    APPEND wa_sdata-low TO ITAB_data.
  ENDLOOP.

  DESCRIBE TABLE ITAB_data LINES lv_lines." Here we get total number of record
  WHILE sy-index < lv_lines. " Loop the whole record till all data are compared
    READ TABLE ITAB_data INTO wa_bubble_data INDEX 1. "Read 1st data into a field
    LOOP AT ITAB_data INTO  wa_current_data   FROM 2 TO lv_lines - sy-index + 1. " Read data from 2nd record onwards
      lv_current_line = sy-tabix. " Gives current loop number
      IF ( wa_bubble_data > wa_current_data ). " If record no.2 > record no.1 => SWAP them
        MODIFY ITAB_data FROM wa_bubble_data INDEX lv_current_line.
        MODIFY ITAB_data FROM wa_current_data INDEX lv_current_line - 1.
      ELSE.
        wa_bubble_data = wa_current_data. " If not, 2nd record will become first and 3rd record will become 2nd record
      ENDIF.
    ENDLOOP.
  ENDWHILE.

  LOOP AT ITAB_data INTO wa_current_data.
    SKIP.
    WRITE : wa_current_data.
  ENDLOOP.