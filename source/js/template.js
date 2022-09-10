//Elementの表示、非表示を切り替える。
function toggleElement(id)
{
    let ele = document.getElementById(id);
    if(ele.classList.contains('d-none'))
    {
        ele.classList.remove('d-none');
        ele.classList.add('d-block');
        return;
    }
    if(ele.classList.contains('d-block'))
    {
        ele.classList.remove('d-block');
    }
    ele.classList.add('d-none');
}

//目次を追加したい要素、目次を検索する親要素
function displayTableContents(ele,parent)
{
    const chileds = parent.childNodes;
    let string ="";
    for(let i = 0;i < chileds.length;i++)
    {
        const chiled = chileds.item(i);
        if(chiled.tagName!='LI') continue;
        const content = document.createElement('a');
        content.href = '#' + chiled.id;
        content.innerHTML = chiled.textContent;
        content.classList.add('margin-left');

        ele.append(content);
       
    }
}

document.body.classList.add('background-color');