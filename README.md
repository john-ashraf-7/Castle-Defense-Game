
<h1>Castle Defense Game</h1>
<p><strong>Project Duration:</strong> November 2023 – December 2023</p>

<h2>Play the Game</h2>
<p>Want to experience the excitement of Castle Defense? You can download and play the game directly! Follow these steps:</p>
<ol>
    <li><a href="https://drive.google.com/file/d/1dMFJ-ilPXxKHw_7dP16MdVBQuzqX6OPG/view?usp=sharing" target="_blank">Download a deployed version of the game here</a>.</li>
    <li>Run <code>ClashOfClans.exe</code> to start the game and enjoy!</li>
</ol>
<p><strong>Note:</strong> No additional installations are required to play the game.</p>


<h2>Overview</h2>
<p>Castle Defense is a strategic tower defense game developed by a team of three using C++ and the Qt framework. Players must defend their castle from waves of enemy troops by strategically placing defenses and upgrading their arsenal. The game employs advanced algorithms and Object-Oriented Programming (OOP) principles for engaging gameplay and efficient design.</p>

<h2>Game Features</h2>
<ul>
    <li><strong>Login System:</strong> Players can log in or sign up through a login window implemented using hash tables.</li>
    <li><strong>Market System:</strong> At the start of the game, and between levels, players can purchase or upgrade items such as fences and cannons.</li>
    <li><strong>Object Inheritance:</strong> Classes like Castle, Cannon, Bullet, Fence, and Troops inherit from a base Object class, sharing attributes such as health while having distinct functionalities and graphics.</li>
    <li><strong>Game Mechanics:</strong>
        <ul>
            <li>Troops are spawned using a <code>QTimer</code>, and their movement is controlled by the A* algorithm to navigate toward the castle.</li>
            <li>Collisions with fences or the castle reduce health, while collisions with bullets cause troops to disappear if their health reaches zero.</li>
            <li>Health and damage attributes in multiple classes facilitate easy level adjustments by changing these values.</li>
        </ul>
    </li>
    <li><strong>Dynamic Levels:</strong> The game consists of 5 levels, each with unique themes (different images, music, and sound effects). The player can upgrade defenses between levels using tokens.</li>
    <li><strong>Endings:</strong> A happy ending plays if the player wins, and a sad ending plays if the player loses. Player statistics are displayed at the end.</li>
    <li><strong>Sound and Animation:</strong> Sound effects, theme music, and animations add to the immersive gameplay experience.</li>
</ul>

<h2>Technical Details</h2>
<ul>
    <li><strong>Algorithms:</strong> 
        <ul>
            <li>Implemented the A* algorithm for pathfinding, enabling troops to find the shortest path to the castle.</li>
            <li>Used Euclidean distance calculations for gameplay mechanics, such as targeting and shooting.</li>
        </ul>
    </li>
    <li><strong>Forward Declaration:</strong> Used to resolve circular dependencies between classes, such as the Levels class containing Troops objects that point back to the Levels class.</li>
    <li><strong>Class Aggregation:</strong> 
        <ul>
            <li>Bullet objects are instantiated in the Cannon class, and their movement is managed using a unit vector equation.</li>
            <li>The Levels class serves as the main hub where all game actions occur, aggregating with Castle, Cannon, Fence, and Troops classes.</li>
        </ul>
    </li>
    <li><strong>Graphics Handling:</strong> Each game object (e.g., Troops, Cannon) uses a <code>QGraphicsPixmapItem</code> for visual representation.</li>
</ul>

<h2>Technologies Used</h2>
<ul>
    <li>C++</li>
    <li>OOP</li>
    <li>Qt Framework</li>
    <li>Additional Qt Libraries</li>
</ul>

<h2>Getting Started</h2>
<p>To play the game, clone the repository, and build the project using Qt Creator or another compatible IDE. Make sure the Qt framework is installed as well as the QtMultiMedia Library and configured on your system.</p>

<h2>Team members</h2>

<ul>
  <li>
    John Ibrahim <br>
  </li>
  <li>
    Omar Ganna <br>
  </li>
  <li>
    Tony Gerges
  </li>
</ul>
