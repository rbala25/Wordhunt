# Word Hunt Arduino Robot
<b>Author:</b> Rishi Bala  
<b>Email:</b> rishibala2007@gmail.com  
<b>Repository:</b> https://github.com/rbala25/wordhunt
<br>
<b>Demo:</b> https://drive.google.com/file/d/1tO_AUnHh0qJxfuCMQtUR4q44hPh-JSbv/view?usp=sharing

<br>
<h3>Hardware</h3>
<ul>
<li>Uses two micro servo motors to get complete movement on the Word Hunt board.</li>
<li>Uses a q-tip and a cut pen wrapped in aluminum foil with electrical current as a conductive stylus.</li> 
<li>The stylus is picked up and put down using a third micro servo motor.</li>
<li>A 9-Volt battery with a voltage divider powers the motors.</li>
</ul>

<br>
<h3>Software</h3>
<ul>
<li>The user inputs all 16 letters into a Java script, which then finds all possible words.</li>
<li>The Java script uses a Trie data structure parsing words from the 2019 Collins dictionary.</li>
<li>The information about each possible word is sent over socket communication to a Python script.</li>
<li>The Python script encodes the information and sends it over Serial to the Arduino.</li>
</ul>
