### T (分时)
MA30:=EMA(CLOSE,30);
强弱:EMA(CLOSE,900);
STICKLINE((MA30>强弱),MA30,强弱,1,0),COLOR0000FF;
STICKLINE((MA30<强弱),MA30,强弱,1,0),COLOR00FF00;
H1:=MAX(DYNAINFO(3),DYNAINFO(5));
L1:=MIN(DYNAINFO(3),DYNAINFO(6));
P1:=H1-L1;
阻力:L1+P1*7/8,COLOR00DD00;
支撑:L1+P1*0.5/8,COLOR00DD00;
现价:CLOSE,COLORWHITE,LINETHICK1;
STICKLINE(CROSS(支撑,现价),支撑,阻力,1,0),COLORYELLOW;
DRAWTEXT(LONGCROSS(支撑,现价,2),支撑*1.001,'★B'),COLORYELLOW;{吸}
DRAWTEXT(LONGCROSS(现价,阻力,2),现价,'★'),COLORRED;{抛};