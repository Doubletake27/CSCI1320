/*
var tasks = []
*/
var cats = ["Outdoor","Service","Educational"];
var tags = ["COVID","People","Quirky"];

function loadTasks(team,comp){
  console.log("Page Loaded");

  // Populate Categories
  // var i;
  // for(i = 0; i<cats.length; i++){
  //   addCategory(cats[i]);
  // }
  addCategory("SPACE TEST");

  // this function will then populate tasks
  // Grey out completed tasks

  // Will be eventually part of add Tasks
  loadTags(1); //Task ID
  // load Stats
  loadStats(1,1); // TeamID ,CompetetionID
}

// Load Stats
function loadStats(team,comp){
  // Calculate and Populate Statistics Table
  document.getElementById("completedTasks").innerHTML = "24/106";
  document.getElementById("score").innerHTML = 48;
  document.getElementById("rank").innerHTML = "7/36";
  document.getElementById("timeRemaining").innerHTML = "1h 34m";
  console.log("Stats Updated")
}

// Add Category
function addCategory(name){
  var title = name;
  // name needs no spaces in order to be vaild for naming later on
  name = name.split(" ").join("");
  console.log(name);

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
  // (X)       Category 2 Tasks
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
  // var d2ID = [name,"Head"].join(' '); // create Header ID string
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

  // // ----- Create Hierarchy ----- // //
  catHead.appendChild(d1);
  d1.appendChild(d2);
  d1.appendChild(d6);
  d2.appendChild(d3);
  d3.appendChild(d4);
  d4.appendChild(d5);
  d6.appendChild(d7);

  console.log("Category Added");
  console.log(catHead.innerHTML);
}

// Add Task
function addTask(tID){

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

// Submit Task
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
