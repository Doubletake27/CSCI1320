// // The Tasks array would be pulled from the server based on a competetion specifice querey
var tasks = [
 {
   "ID": 1,
   "Category": "College",
   "Tags": "\"Food\"",
   "Title": "Dining Hall Friend",
   "Descripton": "Take a photo with someone currently working at a dining hall on campus",
   "Points": 4
 },
 {
   "ID": 2,
   "Category": "College",
   "Tags": "\"COVID\",\"Outdoor\"",
   "Title": "Beautiful Campus",
   "Descripton": "Take a picture of a member of your group in what you consider to be the prettiest part of the campus",
   "Points": 4
 },
 {
   "ID": 6,
   "Category": "College",
   "Tags": "",
   "Title": "RA on Duty",
   "Descripton": "Take a photo with an RA currently wearing a lanyard indicating that they are on duty",
   "Points": 3
 },
 {
   "ID": 7,
   "Category": "Physical",
   "Tags": "\"Physical\", \"COVID\",\"Geotagged\"",
   "Title": "Hike the First Flatiron",
   "Descripton": "Hike from Chatequa Park parking lot to the top of the first flat iron and and take a photo at the top",
   "Points": 11
 },
 {
   "ID": 8,
   "Category": "Physical",
   "Tags": "\"Physical\",\"Outdoor\"",
   "Title": "Do 15 jumping jacks",
   "Descripton": "Take a photo midair of a jumping jack",
   "Points": 2
 },
 {
   "ID": 9,
   "Category": "Physical",
   "Tags": "\"Outdoor\",\"Physical\"",
   "Title": "Walk around a track",
   "Descripton": "",
   "Points": 3
 },
 {
   "ID": 13,
   "Category": "Quirky",
   "Tags": "\"LA\"",
   "Title": "Honk at a Goose",
   "Descripton": "Take a photo of yourself honking at a goose",
   "Points": 2
 }
]
var tags = ["COVID","People","Quirky"]; // will be built into Tasks Array
var cats = [];

// // // --- --- --- LOAD TASK PAGE --- --- --- // // //
function loadTaskPage (team,comp){
  console.log("Page Begin");
  // Populate Task Array JSON from Challenge Database

  // Create Category Array
  var i;
  var j;
  var unique = true;
  cats[0] = tasks[1].Category;
  addCategory(cats[0]);
  for(i = 0; i<tasks.length; i++){
    for(j = 0; j<cats.length; j++){
      if(cats[j]==tasks[i].Category){
        // console.log(i+","+j+" "+cats[j]+" "+tasks[i].Category);
        match = false;
      }
    }
    if(match){
      cats.push(tasks[i].Category);
      addCategory(cats[cats.length-1]); //Creates new array
    }
    match = true;
  }



  // Populate Categories (FOR TESTING ONLY)
  // var cats = ["Outdoor","Community Service","Educational"];
  // for(i = 0; i<cats.length; i++){
  //   addCategory(cats[i]);
  // }
  // addCategory("SPACE TEST"); // This is for testing only

  // Populate Tasks

  // this function will then populate tasks
  // Grey out completed tasks

  // Will be eventually part of add Tasks
  loadTags(1); //Task ID
  // load Stats
  loadStats(1,1); // TeamID ,CompetetionID
}

// // // --- --- --- Load Stats --- --- --- // // //
function loadStats(team,comp){
  // Calculate and Populate Statistics Table
  document.getElementById("completedTasks").innerHTML = "24/106";
  document.getElementById("score").innerHTML = 48;
  document.getElementById("rank").innerHTML = "7/36";
  document.getElementById("timeRemaining").innerHTML = "1h 34m";
  console.log("Stats Updated")
}

// // // --- --- --- Add Category --- --- --- // // //
function addCategory(name){
  var title = name;
  // name needs no spaces in order to be vaild for naming later on
  name = name.split(" ").join("");
  // console.log(name);

  // Header ID = categoryAccordian

  // (1) <div class="card">
  // (2)   <div class="card-header bg-info" id="category02Head">
  // (3)     <h2 class="mb-0">
  // (4)       <button class="btn text-white btn-block text-left collapsed" type="button" data-toggle="collapse" data-target="#catCollapse02" aria-expanded="false" aria-controls="catCollapse02">
  // (X)         <!-- Category 2 Title -->
  // (X)         Category 2 Title
  // (5)         <span class="badge badge-secondary">XX/YY</span>
  // (X)         <!-- End Category 2 Title -->
  // (4)       </button>
  // (3)     </h2>
  // (2)   </div>
  // (6)   <div id="catCollapse02" class="collapse" aria-labelledby="category02Head" data-parent="#categoryAccordion">
  // (7)     <div class="card-body">
  // (X)       <!-- Category 2 Tasks -->
  // (8)       <div class="accordion" id="accordionExample">
  // (X)        Category 2 Tasks
  // (8)       </div>
  // (X)       <!-- End Category 2 Tasks -->
  // (7)     </div>
  // (6)   </div>
  // (1) </div>

  // Tasks Nested within "Category 2 Tasks"

  // // ----- Header ----- // //
  var catHead = document.getElementById('categoryAccordion');
  // (1) <div class="card">
  var d1 = document.createElement('div');
  d1.classList.add("card");
  // (2)   <div class="card-header bg-info" id="category02Head">
  var d2 = document.createElement('div');
  d2.classList.add("card-header");
  d2.classList.add("bg-info");
  var d2ID = name+"Head"; // create Header ID string
  d2.id = d2ID;
  // (3)     <h2 class="mb-0">
  var d3 = document.createElement('h2');
  d3.classList.add("mb-0");
  // (4)       <button class="btn text-white btn-block text-left collapsed" type="button" data-toggle="collapse" data-target="#catCollapse02" aria-expanded="false" aria-controls="catCollapse02">
  var d4 = document.createElement('button');
  d4.classList.add('btn');
  d4.classList.add('text-white');
  d4.classList.add('btn-block');
  d4.classList.add('text-left');
  d4.classList.add('collapsed');
  d4.setAttribute("type","button");
  d4.setAttribute("data-toggle","collapse");
  var d4TGT = "catCollapse"+name;
  var d4TGT2 ="#catCollapse"+name;
  d4.setAttribute("data-target",d4TGT2);
  d4.setAttribute("aria-expanded","false");
  d4.setAttribute("aria-controls",d4TGT);
  d4.innerHTML = title + " "; // Setting Category Title
  // (5)         <span class="badge badge-secondary">XX/YY</span>
  var d5 = document.createElement('span');
  d5.classList.add('badge');
  d5.classList.add('badge-secondary');
  d5.innerHTML = "AA/ZZ"; // Number of Tasks completed - to be updated later
  // (6)   <div id="catCollapse02" class="collapse" aria-labelledby="category02Head" data-parent="#categoryAccordion">
  var d6 = document.createElement('div');
  d6.id = d4TGT;
  d6.classList.add('collapse');
  d6.setAttribute("aria-labelledby",d2ID);
  d6.setAttribute("data-parent","#categoryAccordion")
  // (7)     <div class="card-body">
  var d7 = document.createElement("div");
  d7.classList.add("card-body");
  d7.innerHTML = "New Tasks Dynamically added here";
  // (8)       <div class="accordion" id="accordionExample">
  var d8 = document.createElement("div");
  d8.classList.add("accordian");
  d8.id = "taskAccordian"+name;
  // // ----- TASK INSERTION HERE ----- // //


  // // ----- Create Hierarchy ----- // //
  catHead.appendChild(d1);
  d1.appendChild(d2);
  d1.appendChild(d6);
  d2.appendChild(d3);
  d3.appendChild(d4);
  d4.appendChild(d5);
  d6.appendChild(d7);

  console.log("Category Added: "+title);
  // console.log(catHead.innerHTML);
}

// // // --- --- --- Add Task --- --- --- // // //
function addTask(catName,tID){
  // (1) <div class="card">
  // (2)   <div class="card-header" id="headingOne">
  // (3)     <h2 class="mb-0">
  // (4)       <button class="btn btn-block text-left" type="button" data-toggle="collapse" data-target="#collapseOne" aria-expanded="false" aria-controls="collapseOne">
  // (X)         Task 1 Title
  // (5)         <span class="badge badge-info">Pts</span>
  // (4)       </button>
  // (3)     </h2>
  // (2)   </div>
  // (6)   <div id="collapseOne" class="collapse" aria-labelledby="headingOne" data-parent="#accordionExample">
  // (7)     <div class="card-body">
  // (X)       <!-- Task 1 Contents  -->
  // (8)         <div class="alert alert-secondary" role="alert">
  // (X)           This is the description of the task.
  // (8)         </div>
  // (X)         <!-- Submit Task Button-->
  // (9)         <button type="button" class="btn btn-primary" data-toggle="modal" data-target="#submitModal">
  // (X)           Submit Task
  // (9)         </button>
  // (X)         <!-- End Image Upload Button -->
  // (10)        <br/>
  // (X)         <!-- Tags -->
  // (7)     </div>
  // (6)   </div>
  // (1) </div>

  // // ----- Extract Info from tID ----- // //
  // {
  //   "ID": 1,
  //   "Category": "College",
  //   "Tags": "\"Food\"",
  //   "Title": "Dining Hall Friend",
  //   "Descripton": "Take a photo with someone currently working at a dining hall on campus",
  //   "Points": 4
  // }
  var i;
  var idx;

  // Determine Index in Task file relative to ID
  for(i = 0; i<tasks.length; i++){
    if(task[i].ID==tID){
      idx = i;
    }
  }


  // // ----- Header ----- // //
  var catHead = document.getElementById("taskAccordian"+catName);
  // (1) <div class="card">
  var d1 = document.createElement('div');
  d1.classList.add("card");\
  // (2)   <div class="card-header" id="headingOne">
  // (2)   <div class="card-header bg-info" id="category02Head">
  var d2 = document.createElement('div');
  d2.classList.add("card-header");
  d2.classList.add("bg-info");
  d2.id = d2ID;Header ID string
  d2.id = d2ID;Header ID string
  var d2ID = "Task"+tID+"Head"; // create Task Header ID string
  d2.id = d2ID;



  console.log("Task ID:"+tID+" Loaded")
}

function loadTags(tID){
  // <span class="badge badge-secondary">Tag Name</span>
  var i;
  var tagDiv = document.getElementById('T001Tags'); // Need to dynamically change with TaskID
  for(i = 0; i<tags.length; i++){
    var newTag  = document.createElement('span');
    newTag.classList.add("badge");
    newTag.classList.add("badge-secondary");
    newTag.innerHTML = tags[i];
    tagDiv.appendChild(newTag);
  }

  //console.log(tagDiv.innerHTML);
  console.log("Tags Loaded")
}

// // // --- --- --- Submit Task --- --- --- // // //
function submitTask(tID){
  // Task Submission
  //   Submission ID [Primary Key]
  //   Event ID
  //   Task ID
  //   Image
  //   Description

  // Generate Submission ID
  //  EventID-TeamID-TaskID
  // Pull Event ID

  // Pull Task ID

  // Image

  // Descripton
  var comment = document.getElementById("taskComment").value;
  console.log(comment);
  // Package Together into Schema

  // Push to Server

}
