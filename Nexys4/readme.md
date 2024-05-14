<!DOCTYPE html>
<html>
<head>
<style>
ul, #myUL {
  list-style-type: none;
}

#myUL {
  margin: 0;
  padding: 0;
}

.caret {
  cursor: pointer;
  user-select: none;
}

.caret::before {
  content: "\\25B6";
  color: black;
  display: inline-block;
  margin-right: 6px;
}

.caret-down::before {
  transform: rotate(90deg);
}

.nested {
  display: none;
}

.active {
  display: block;
}
</style>
</head>
<body>

<h2>可点击的树</h2>

<ul id="myUL">
  <li><span class="caret">文件夹1</span>
    <ul class="nested">
      <li>文件1.1</li>
      <li>文件1.2</li>
    </ul>
  </li>
  <li><span class="caret">文件夹2</span>
    <ul class="nested">
      <li><span class="caret">子文件夹2.1</span>
        <ul class="nested">
          <li>文件2.1.1</li>
          <li>文件2.1.2</li>
        </ul>
      </li>
      <li>文件2.2</li>
    </ul>
  </li>
</ul>

<script>
var toggler = document.getElementsByClassName("caret");
var i;

for (i = 0; i < toggler.length; i++) {
  toggler[i].addEventListener("click", function() {
    this.parentElement.querySelector(".nested").classList.toggle("active");
    this.classList.toggle("caret-down");
  });
}
</script>

</body>
</html> 
