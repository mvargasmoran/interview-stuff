<script>
  export let pageTitle;

  let lastInput = Date.now();
  let autoSaveTimer;

  function serverStuff(data){
    setTimeout(function () {
      return {
        message: "demo"
      };
    }, 1000);
  }

  $: savedAlert = document.getElementById('saved-alert');
  function autoSave(){
    let rightNow = Date.now();
    console.log({rightNow, lastInput});

    let timeSinceLastInput = (rightNow - lastInput);
    let shouldAutoSave = timeSinceLastInput >= 2000;
    if(shouldAutoSave) {
      console.log('Im going to auto-save, you are idle')
      data = {
        product: 'bacon',
        quantity: targetInput.value,
      };

      let saved = serverStuff(data);
      savedAlert.classList.add('saved');
      setTimeout(()=>{
        savedAlert.classList.remove('saved');
      }, 1200);
    }
  }

  const keyupHandle = () => {
    console.log('keyup>>>')
    lastInput = Date.now();
    clearTimeout(autoSaveTimer);
    autoSaveTimer = setTimeout(autoSave, 2000);
  }
</script>

<main>
  <div class="stylish-form">
    <div class="page-title">
      <h1>{pageTitle} Buy your Bacon</h1>
    </div>

    <div class="image-container">
      <img class="smooth" src="https://img.estadao.com.br/resources/jpg/2/4/1537398164742.jpg" alt="bacon">
    </div>

    <div class="product-name product-info">
      <h2>Bacon</h2>
    </div>

    <div class="input-container product-info">
      <label for="productQuantity">Product Quantity</label>
      <input id="targetInput" name="productQuantity" type="number" on:keyup={keyupHandle}>

      <div id="saved-alert" class="autosaving-alert">
        Auto-saving...
      </div>
    </div>
  </div>
</main>


<style lang="scss">
  main {
    padding: 1em;
    border: 1px solid hotpink;
    margin: 0 auto;
    display: block;
    width: 70%;
  }
  .autosaving-alert{
    font-size: 11px;
    font-style: italic;
    display: inline-block;
    opacity: 0;
    &.saved{
      animation: AnimationName 1.2s ease infinite;
      background: linear-gradient(90deg, #71c356, #4a730c);
      background-size: 400% 400%;
    }
  }

  .stylish-form {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    grid-auto-rows: minmax(100px, auto);
    row-gap: 10px;
    column-gap: 10px;
    > div {
      outline: 1px solid green;
      background: rgba(10,10, 240,.1);
    }
  }
  .page-title{
    text-align: center;
    grid-column: 1 / 4;
    grid-row: 1;
  }
  .image-container{
    grid-column: 1 / 2;
    grid-row: 2 / 5;
    > img {
      position: relative;
      width: 100%;
    }
  }
  .product-info{
    padding: 15px;
  }
  .product-name{
    grid-column: 2 / 4;
    grid-row: 2 / 3;
  }
  .input-container{
    grid-column: 2 / 4;
    grid-row: 3 / 5;
  }
  h1 {
    color: #ff3e00;
    text-transform: uppercase;
    font-size: 4em;
    font-weight: 100;
  }

  @media (min-width: 640px) {
    main {
      max-width: none;
    }
  }


  @keyframes AnimationName {
    0%{
      opacity: 0;
      transform: translateX(-40px);
      background-position:0% 50%;
    }
    40%{
      opacity: 1;
      transform: translateX(0px);
      background-position:100% 50%
    }
    80%{
      opacity: 1;
      transform: translateX(0px);
      background-position:100% 50%
    }
    100%{
      opacity: 0;
      ransform: translateX(400px);
      background-position:0% 50%
    }
  }
</style>
