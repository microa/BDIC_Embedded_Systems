## ADC on ToolStick-UniDC-UG

<br> The schematic of the on-board adjustable voltage-divider circuit is shown on <b>Brightspace Lab 1 - ToolStick-UniDC-UG (Page15)</b>, as below:

<img src="./Sch.png" height="200px">

<br> The voltage divider can be simplified as below:

<img src="./VoltageDivider.png" height="200px">

<br> Here is the equation:

V<sub>out</sub> = $\frac{V_{s} \cdot R_{2}}{R_{1} + R_{2}}$

<br> So while the Vs = 3.3v, R1 = 3.74k, R2 = 10k, the largest voltage output would be: 2.402 V

<br> Note: this is a theoretical result. Only when the power source is exactly 3.3 V and every resistor was perfectly they are.

<br> Rescaling code:
  
    Number = val_adc * 2402 / 4096;  //software rescaling
