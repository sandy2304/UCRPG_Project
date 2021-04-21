 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# UCRPG

 > Authors: \<[Dylan Fragante](https://github.com/sandy2304)\>
            \<[David Tellez](https://github.com/Davtellez01)\>
            \<[Alexander Trejo](https://github.com/trejotrejotrejo)\>
 
 ## Project Description
 > * This is an RPG based on UCR campus and its different departments.
 > * We think that this project would be fun and engaging to do. 
 > * Languages/tools/technologies
 >   * [C++] - to code the game.
 >   * [Image to ASCII converter](https://manytools.org/hacker-tools/convert-images-to-ascii-art/) - converts images into ASCII characters to implement into the code.
 > * Input/Output
 >   * Input: Different keys to interact with the game. Keyboard strings.
 >   * Output: Text from player's input. ASCII pictures based on different events.
 > * Design Patterns 
 >   * Abstract Factory 
 >     * The abstract factory pattern will help with the creation of multiple entities that share the same traits but are specifically different to one another. This can be used to create different multiple types of enemies, areas, or classes. The different departments could have their own parent classes and we can make sub classes of that parent class to create multiple types of the same enemy, but with different statistics. This design pattern will solve the problem of creation of many classes with the same traits.
 >   * Builder 
 >     * The builder pattern allows us to organize object construction into a set of steps. We picked this pattern because with the creation of many different characters, some will have different aspects but will derive from the same base, along with additions based on what they are. The additions could range from whether the player / enemy has a weapon or not, whether they can wield magic, etc., but each character will have statistics from the same class. In order to prevent making many of the same instances of it which will lead to slower development time, we can just use the builder pattern so that the creation is quick and easy to implement into the game without excess work. 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
